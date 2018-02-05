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
    "regexp"
)

func main() {
    for {
        if random.IntRange(0, 100) == 0 {
            fmt.Println("fuck")
        }
    }
}
