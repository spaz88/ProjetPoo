<?php

include_once 'Card.php';

class Deck {

    private $cards;

    public function __construct() {
        $this->cards = array();
    }

    public function getCards($position) {
       return $this->cards[$position];
    }

    public function remaining() : int {
        return count($this->cards);
    }

    public function drawn($n) : void {
        array_push($this->cards, $n);
    }

    public function addOne($card) : void {
        array_push($this->cards, $card);
    }
    



}