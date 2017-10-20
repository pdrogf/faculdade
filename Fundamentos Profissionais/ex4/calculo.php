<?php

$cotacao;
$valor1;
$valor2;
$valor3;

$cotacao = $_POST['cotacao'];
$valor1 = $_POST['valor1'];
$valor2 = $_POST['valor2'];
$valor3 = $_POST['valor3'];

$valor1 = $valor1*$cotacao;
$valor2 = $valor2*$cotacao;
$valor3 = $valor3*$cotacao;

echo "valor1 em reais ".$valor1;
echo "<br>valor2 em reais ".$valor2;
echo "<br>valor3 em reais ".$valor3;


?>