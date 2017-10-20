<?php

$nota1; 
$nota2;
$nota3;
$nota4;
$calc;

$nota1 = $_POST['nota1'];
$nota2 = $_POST['nota2'];
$nota3 = $_POST['nota3'];
$nota4 = $_POST['nota4'];

$calc = ($nota1+$nota2+$nota3+$nota4)/4;

echo $calc;



?>