import './Array.css';
import React, { useState, useRef } from 'react';
import { TextField, Fab } from '@material-ui/core';
import AddIcon from '@material-ui/icons/Add' ;

function Array( { arr } ) {

    const [ array, setArray ] = useState(arr);
    let latestBox = useRef(null);

    function changeNumber(i, e) {
        const arr = [...array];
        arr[i].value = parseInt(e.target.value);
        // console.log(arr[i].value);
        if (arr[i].value === '') {
            arr.splice(i,1); 
        } else {
            console.log(i);
            setArray(arr);
            // latestBox.current.label = "";
            console.log(latestBox.current);
        }

    }
    function newNumber() {
        const arr = [...array];
        if ( arr.length!=0 && arr[arr.length-1].value === null ) {
            //box
            console.log("ff");
        } else {
            arr.push({value:null}); 
            setArray(arr);
        }
    }
    function removeNumber(i) {
        const arr = [...array];
        arr.splice(i,1); 
        setArray(arr);
    }

    return(
        <div className="Array">

            <h1>Add Numbers</h1>
            <br /> <br />

            {array.map( (num,i) => {
                    return (
                        <TextField 
                            id = {"num"+i}
                            key = {i}
                            value={num.value || "" } 
                            variant="outlined"
                            className="number"
                            inputRef={latestBox}
                            inputProps={{
                                style: { textAlign: "center" }
                            }}
                            label="Number"
                            onChange={ (e) => {
                                changeNumber(i,e);
                            }}
                        / >
                    )
                }
            )}

            <br />

            {/* document.getElementById("num"+(array.length-1)).focus(); */}
            <Fab color="primary" aria-label="new-number" onClick={newNumber} >
                <AddIcon />
            </Fab>

        </div>
    )

}

export default Array;