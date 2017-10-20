<?php

$valor1;
$valor2;
$valor3;
$valor4;
$calc;



$valor1 = $_POST['valor1'];
$valor2 = $_POST['valor2'];
$valor3 = $_POST['valor3'];
$valor4 = $_POST['valor4'];

$calc = ($valor1*$valor1) + ($valor2*$valor2) + ($valor3*$valor3) + ($valor4*$valor4);

echo $calc;

?>