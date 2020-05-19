import React, { Component } from 'react'
import { Text, View ,FlatList, Button, Image} from 'react-native'


export default class FlatDemo extends Component {

    constructor(props){
        super(props)
        this.max=4
        this.state={data:[],albums:[]}
        
    }
    componentDidMount(){
        fetch("http://www.cjlly.com:3009/record",{method:"GET"})
        .then(resp=>resp.json())
        .then(albums=>{
            console.log(albums)
            this.setState({albums:albums})
        })
    }
    _renderItem=({item})=>{
        return (
            <View style={{height:120,justifyContent:"space-between"}}>
                <View style={{alignItems:"center"}}>
                <Text >{item.name}</Text>    
                
                </View>
                
                <Image style={{width:70,height:70}} source={{uri:item.img}}/>
                <Button title="xxx"/>
            </View>
        )
    }
    _ItemSeparatorComponent=()=>{
        return <View style={{height:1,backgroundColor:"red"}}></View>
    }

    _refresh=()=>{
        let d=Math.floor(Math.random()*100+100)
        let data=this.state.data.splice(0)
        data.unshift(d)
        this.setState({data:data})
    }
    _reachEnd=()=>{
        let data=this.state.data.splice(0)
        data.push(++this.max)
        this.setState({data:data})
    }
    _ajax=()=>{
        
    }


    render() {
        return (
            <View>
                <Button title="AJAX" onPress={this._ajax}/>
                <FlatList
                    keyExtractor={({item,index})=>index}
                    ItemSeparatorComponent={this._ItemSeparatorComponent}
                    data={this.state.albums} 
                    renderItem={this._renderItem}
                    // refreshing={false}
                    // onRefresh={this._refresh}
                    // onEndReached={this._reachEnd}
                    // onEndReachedThreshold={0.2}
                />
            </View>
        )
    }
}
