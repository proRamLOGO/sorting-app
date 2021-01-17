// import logo from './logo.svg';
import './App.css';
import React, { useState } from 'react';
import Array from './Array' ;
import ListOfNumbers from './ListOfNumbers' ;

import { makeStyles } from '@material-ui/core/styles';
import AppBar from '@material-ui/core/AppBar';
import Toolbar from '@material-ui/core/Toolbar';
import Typography from '@material-ui/core/Typography';
import Button from '@material-ui/core/Button';

import Dialog from '@material-ui/core/Dialog';
import DialogActions from '@material-ui/core/DialogActions';
import DialogContent from '@material-ui/core/DialogContent';
import DialogContentText from '@material-ui/core/DialogContentText';
import DialogTitle from '@material-ui/core/DialogTitle';

import "react-loader-spinner/dist/loader/css/react-spinner-loader.css"
import Loader from 'react-loader-spinner'

const useStyles = makeStyles((theme) => ({
  root: {
    flexGrow: 1,
  },
  menuButton: {
    marginRight: theme.spacing(2),
  },
  title: {
    flexGrow: 1,
  },
  submitButton: { 
    marginTop: '80px',
    marginBottom: '100px',
  },
  appBar: {    
    // background-color: #2f2f2f;
    position: 'fixed' ,
    width: '100%' ,
    bottom: 0 ,
    left: 0 ,
    textDecoration: 'none',
    // color: #fff ;
    right: 0,
  },
  appBarA: {    
    textDecoration: 'none',
    color: '#fff',
    fontWeight: 'bold',
  },
}));

function App() {
  const classes = useStyles();
  const [array, setArray] = useState([]);
  const [dispList, setDispList] = useState(false);
  const [open, setOpen] = React.useState(false);

  const handleClose = () => {
    setOpen(false);
  };

  return (
    <>

    <Loader type="BallTriangle" className="preLoader" color="#00BFFF" height={80} width={80} timeout={1000} />

    <div className="App">
      <AppBar position="static" className={classes.appBar}>
        <Toolbar>
          <Typography variant="h6" className={classes.title}>
            AppSORT - By <a className={classes.appBarA} href="http://proramlogo.github.io/">Shubh Bansal</a>
          </Typography>
        </Toolbar>
      </AppBar >
      
      <Array arrOriginal={array} setArr={setArray} dispList={dispList} setDispList={setDispList} />

      <ListOfNumbers array={array} dispList={dispList} setDispList={setDispList} />

      <Button variant="contained" color="primary" className={classes.submitButton}
        onClick={ () => { 
          const sa = [...array];
          for ( var i=0 ; i<sa.length ; i++ ) {
            if (document.getElementById(('num'+i)).value=='') {
              setOpen(true);
              return;
            }
          }
          if (sa[sa.length-1].value == null) 
            sa.pop();
          sa.sort( (a,b) => (a.value > b.value) ? 1 : ((b.value > a.value) ? -1 : 0) );
          console.log(sa);
          setArray(sa);
          setDispList(true);
        }}>
        SORT!
      </Button>      

      <Dialog
        open={open}
        onClose={handleClose}
        aria-labelledby="alert-dialog-title"
        aria-describedby="alert-dialog-description"
      >
        <DialogTitle id="alert-dialog-title">{"Look Around!"}</DialogTitle>
        <DialogContent>
          <DialogContentText id="alert-dialog-description">
            {"Fill in that empty box first"}
          </DialogContentText>
        </DialogContent>
        <DialogActions>
          <Button onClick={handleClose} color="primary">
            OK
          </Button>
        </DialogActions>
      </Dialog>

    </div>
    </>
  );
}

export default App ;
