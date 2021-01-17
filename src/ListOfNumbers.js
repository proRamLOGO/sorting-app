import React from 'react';
import {Paper, Typography} from '@material-ui/core';
import { makeStyles } from '@material-ui/core/styles';

const useStyles = makeStyles((theme) => ({
    root: {
      display: 'flex',
      flexWrap: 'wrap',
      justifyContent: 'center',
      textAlign: 'left',
      bottom: '0',
      paddingTop: '3em',
      transition: 'easeIn',
      '& > *': {
        margin: 'auto',
        width: 'auto',
        height: 'auto',
        padding: theme.spacing(3),
      },
    },
  }));

function ListOfNumbers({array, dispList, setDispList }) {
    const classes = useStyles();
    if ( !dispList ) {
        return ( <></> );
    }
    // setDispList(false);
    return (
        <div className={classes.root}>
            {/* <Drawer PaperProps={{ elevation: 10 }}/> */}
            <Paper variant="outlined" zDepth={6} >
                <Typography variant="h6" >List of Sorted Numbers</Typography>
                <Typography variant="h5" >{array.map((num) => {return num.value} ).join(", ")}</Typography>
            </Paper>
        </div>
    )

}

export default ListOfNumbers;