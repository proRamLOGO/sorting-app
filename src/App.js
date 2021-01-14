// import logo from './logo.svg';
import React, { useState } from 'react';
import './App.css';
import TextField from '@material-ui/core/TextField';
import Array from './Array' ;

import { makeStyles } from '@material-ui/core/styles';
import AppBar from '@material-ui/core/AppBar';
import Toolbar from '@material-ui/core/Toolbar';
import Typography from '@material-ui/core/Typography';

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
}));

function App() {
  const classes = useStyles();
  const [array, setArray] = useState([]);

  return (
    <>

    <Loader type="BallTriangle" className="preLoader" color="#00BFFF" height={80} width={80} timeout={3000} />

    <div className="App">
      <AppBar position="static">
        <Toolbar>
          <Typography variant="h6" className={classes.title}>
            AppSORT
          </Typography>
        </Toolbar>
      </AppBar >
      
      <Array arr={array} />



    </div>
    </>
  );
}

export default App ;
