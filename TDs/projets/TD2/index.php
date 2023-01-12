<?php

include_once 'CPersonnel.php';

// Création des objets
$p1 = new CPersonnel();

$e1 = new CCommercial("flo", "flo", 23, 3, 15000);
$e2 = new CTechnicien("lukas", "lukas", 18, 2, 1500);
$e3 = new CManutentionnaire("doryan", "doryan", 19, 10, 45);
$e4 = new CCommercial("Gasard", "gaspard", 21, 1, 10000);

// Ajout au tableau 
$p1->embaucher($e1);
$p1->embaucher($e2);
$p1->embaucher($e3);
$p1->embaucher($e4);

// Test des fonctions
$p1->printSalaire();

echo "<br />";

$p1->salaireMoyen();

echo "<br />";

// On fait faillite 
$p1->faillite();
var_dump($p1);