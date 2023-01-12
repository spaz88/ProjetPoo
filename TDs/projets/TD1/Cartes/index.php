<?php

error_reporting(E_ALL);
ini_set("display_errors", 1);

include_once 'Card.php';
include_once 'Deck.php';

$carte1 = new Card("AS", "Carreau");
$carte2 = new Card("10", "Treffle");

$deck = new Deck();
$deck->addOne($carte1);
$deck->addOne($carte2);


for($i = 0; $i < $deck->remaining(); $i++) {
    $deck->getCards($i)->display();
    echo '<br/>';
}


?>