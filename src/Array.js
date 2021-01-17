import './Array.css';
import React, { useRef } from 'react';
import { TextField, Fab, Tooltip } from '@material-ui/core';
import AddIcon from '@material-ui/icons/Add' ;

function NumberTeller( {array} ) {
    console.log(array.length);
    if ( array.length>1 ) {
        return (
            <h3> Total {array.length} numbers. </h3> 
        )
    } else {
        return (
            <>
            </>
        )
    }
}

function Array( { arrOriginal, setArr, dispList, setDispList } ) {

    const array = arrOriginal;
    const setArray = setArr;

    let latestBox = useRef(null);

    function changeNumber(i, e) {
        const arr = [...array];
        arr[i].value = parseInt(e.target.value);
        // console.log(arr[i].value);
        setArray(arr);

    }
    function newNumber(e) {
        const arr = [...array];
        if ( arr.length!==0 && arr[arr.length-1].value === null ) {
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

            <h1>Add Numbers to Sort</h1>
            <br /> 
            <NumberTeller array={array} />
            <br />

            {array.map( (num,i) => {
                    return (
                        <TextField 
                            id = {"num"+i}
                            key = {i}
                            value={num.value || "" } 
                            variant="outlined"
                            className="number"
                            inputRef={latestBox}
                            autoFocus={true}
                            inputProps={{
                                style: { textAlign: "center" }
                            }}
                            label={"Number "+(i+1)}
                            onChange={ (e) => {
                                setDispList(false);
                                changeNumber(i,e);
                            }}
                        / >
                    )
                }
            )}

            <br />

            <Tooltip title="Add a new number" aria-label="add">
                <Fab color="primary" aria-label="new-number" onClick={newNumber} >
                    <AddIcon />
                </Fab>
            </Tooltip>

        </div>
    )

}

export default Array;