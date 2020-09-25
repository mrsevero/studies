import React, { Component } from "react";
import '../node_modules/bootstrap/dist/css/bootstrap.min.css';

import Login from './components/Login/Login.js';
import Cadastro from './components/Cadastro/Cadastro.js';
// Importanto o component <Switch /> e <Route /> da nossa Lib de rotas
import { Switch, Route } from 'react-router-dom'


const App = () => (
    <div className="App">
      <Switch>
        <Route exact path='/' component={Login}/>;
        <Route path='/cadastro' component={Cadastro}/>;
      </Switch>
    </div>
);

export default App;
