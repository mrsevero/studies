import React, { Component } from "react";
import '../node_modules/bootstrap/dist/css/bootstrap.min.css';

import Logo from './components/Logo/Logo.js';
import Login from './components/Login/Login.js';
import Cadastro from './components/Cadastro/Cadastro.js';

const App = () => (
    <div className="App">
      <Logo/>
      <Cadastro/>
    </div>
);

export default App;
