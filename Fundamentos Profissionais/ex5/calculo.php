<?php

$unidade;
$quantidade;
$comissao;


$unidade = $_POST['unidade'];
$quantidade = $_POST['quantidade'];


$comissao = ($unidade*$quantidade)*0.05;

echo "Comissao: ".$comissao;


?>