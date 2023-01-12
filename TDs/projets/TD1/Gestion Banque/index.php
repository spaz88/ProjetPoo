<?php 

include 'Compte.php';

$tit1 = new Titulaire("florian");
$tit2 = new Titulaire("Diego");

$c1 = new Compte($tit1);
$c2 = new Compte($tit2);

$c1->depot(1000);
$c1->getStatusDecouvert();
echo '<br/>';
$c1->virement($c2, 1100);

echo $c2->getSolde();
echo "<br/>";
echo $c1->getSolde();
echo "<br/>";
$c1->getStatusDecouvert();