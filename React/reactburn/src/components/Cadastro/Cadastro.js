import React from 'react';

import "./Cadastro.css";

const Cadastro = () => (
<div className="container">
  <div className="row main">
    <div className="main-login main-center">
      <h5>Cadastre-se para ter acesso a todos os nossos conteúdos</h5>
      <form className method="post" action="#">
        <div className="form-group">
          <label htmlFor="name" className="cols-sm-2 control-label">Nome</label>
          <div className="cols-sm-10">
            <div className="input-group">
              <input type="text" className="form-control" name="name" id="name" placeholder="Digite seu nome" />
            </div>
          </div>
        </div>
        <div className="form-group">
          <label htmlFor="email" className="cols-sm-2 control-label">Email</label>
          <div className="cols-sm-10">
            <div className="input-group">
              <input id="email" onblur="validaEmail(email)" maxLength={60} size={65} type="text" className="form-control" name="email" placeholder="Digite seu email" />
            </div>
          </div>
        </div>
        <div className="form-group">
          <label htmlFor="username" className="cols-sm-2 control-label">Data Nascimento</label>
          <div className="cols-sm-10">
            <div className="input-group">
              <input type="date" className="form-control data" name="date" id="date" placeholder="Digite sua data de nascimento" />
            </div>
          </div>
        </div>
        <div className="form-group">
          <label htmlFor="password" className="cols-sm-2 control-label">Senha</label>
          <div className="cols-sm-10">
            <div className="input-group">
              <input type="password" className="form-control" name="password" id="password" placeholder="Digite sua senha" />
            </div>
          </div>
        </div>
        <div className="form-group">
          <label htmlFor="confirm" className="cols-sm-2 control-label">Confirme a senha</label>
          <div className="cols-sm-10">
            <div className="input-group">
              <input type="password" className="form-control" name="confirm" id="confirm" placeholder="Confirme a sua senha" />
            </div>
          </div>
        </div>
        <div id="formFooter">
          <input onclick="registerUser()" type="button" className="fadeIn fourth" defaultValue="Cadastrar" id="buttomcadastro" />
        </div>
      </form>
    </div>
  </div>
</div>


);

export default Cadastro;