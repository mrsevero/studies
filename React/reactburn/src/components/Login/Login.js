import React from 'react';
import {useHistory} from 'react-router-dom';
import Img from '../../images/logo.png';

import "./Login.css";

function Login() {
  const history = useHistory();

  function handleClick() {
    history.push("/cadastro/");
  }

  return (
    <div>
    <img src={Img} id="logo"/>
    <div className="wrapper fadeInDown ">
      <div id="formContent" className="pt-4">
        {/* Login Form */}
        <form>
          <input type="text" id="login" className="fadeIn second" name="login" placeholder="Email" />
          <input type="password" id="password" className="fadeIn third" name="login" placeholder="Senha" />
          <input onClick="" type="button" className="fadeIn fourth" defaultValue="Entrar" />
        </form>
        <a className="underlineHover ml-4" href="#">Esqueceu a senha?</a>
        {/* Remind Passowrd */}
        <div id="formFooter">
          <input type="button" className="fadeIn fourth botao-cadastro" defaultValue="Cadastrar" onClick={handleClick} />
        </div>
      </div>
    </div>
    </div>
  );
}

export default Login;