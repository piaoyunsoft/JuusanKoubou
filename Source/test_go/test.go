package main

import (
    . "ml/strings"
    . "ml/dict"
    "fmt"
    "os"
    "time"
    "ml/net/http"
    "ml/encoding/json"
    "ml/console"
    "ml/logging/logger"
    "ml/random"
    "ml/html"
    "net"
    "ml/io2"
    "plistlib"
    "reflect"
)

type fuck struct {

}

func (f *fuck) fuckyou() {
    panic("fuck")
}

func main() {
    f := fuck{}
    f.fuckyou()
}
