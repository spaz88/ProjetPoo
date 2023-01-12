<?php

include 'Ctemps.php';

$isChrono = readline("Chronomètre ou Minuteur ? (c/m) : ");
$time = new CTemps(strtolower($isChrono) == "c");

if(strtolower($isChrono) == "c") {
    $time->start();
    sleep(5);
    $time->stop();
} else {
    $time->__add(5);
}

echo $time;
