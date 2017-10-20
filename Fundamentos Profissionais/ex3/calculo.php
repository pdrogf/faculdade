<?php

$nome;
$minimo;
$maximo;
$media;

$nome = $_POST['nome'];
$minimo = $_POST['minimo'];
$maximo = $_POST['maximo'];

$media = ($minimo+$maximo)/2;

echo "Nome peca:".$nome;
echo "<br>Estoque medio:".$media;

?>