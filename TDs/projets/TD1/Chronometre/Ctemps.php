<?php

class CTemps {
    private $time;
    private $isChrono;

    public function __construct($isChrono=true) {
        $this->isChrono = $isChrono;
        $this->time = 0;
    }

    public function start() {
        if($this->isChrono)
            $this->time = time();
    }

    public function stop() {
        if($this->isChrono)
            $this->time = time() - $this->time;
    }

    public function __add($time) {
        if(!$this->isChrono)
            $this->time += $time;
    }

    public function __sub($time) {
        if(!$this->isChrono)
            $this->time -= $time;
    }

    public function __toString() {
        if($this->isChrono)
            return gmdate("H:i:s", $this->time);
        else
            return gmdate("i:s", $this->time);
    }
}
