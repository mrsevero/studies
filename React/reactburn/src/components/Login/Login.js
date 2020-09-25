import React from 'react';

import "./Login.css";

const Login = () => (

<div className="wrapper fadeInDown ">
  <div id="formContent" className="pt-4">
    {/* Login Form */}
    <form>
      <input type="text" id="login" className="fadeIn second" name="login" placeholder="Email" />
      <input type="password" id="password" className="fadeIn third" name="login" placeholder="Senha" />
      <input onclick="userLogin()" type="button" className="fadeIn fourth" defaultValue="Entrar" />
    </form>
    <a className="underlineHover ml-4" href="#">Esqueceu a senha?</a>
    {/* Remind Passowrd */}
    <div id="formFooter">
      <input type="button" className="fadeIn fourth botao-cadastro" defaultValue="Cadastrar" onclick="cadastro" />
    </div>
  </div>
</div>

);


export default Login;