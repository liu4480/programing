package main

import (
    "os/exec"
    "fmt"
    "bytes"
    "os"
    "io/ioutil"
)

func exec_cmd1(cmd string) error {
    command := exec.Command(cmd)
    var out bytes.Buffer
    command.Stdout = &out
    if err := command.Run(); err != nil {
        fmt.Printf("failed to exec %s\n", cmd)
        return err
    }
    fmt.Printf("%s\n", out.String())
    return nil
}

func exec_cmd2(cmd_str string) error {
    cmd := exec.Command(cmd_str)
    out, err := cmd.CombinedOutput()
    if err != nil {
        fmt.Println(err)
        return err
    }
    fmt.Println(string(out))
    return nil
}

func exec_cmd3(cmd_str string) error {
    cmd := exec.Command(cmd_str)
    out, err := cmd.Output()
    if err != nil {
        fmt.Println(err)
        return err
    }
    fmt.Println(string(out))
    return nil
}

func exec_cmd4(cmd_str string) {
    cmd := exec.Command(cmd_str)
    cmd.Stdout = os.Stdout
    cmd.Run()
    fmt.Println(cmd.Start())
}

func exec_cmd5(cmd_str string) error {
    cmd := exec.Command("ls")
    stdin, err := cmd.StdinPipe()
    if err != nil {
        fmt.Println(err)
        return err
    }
    _, err = stdin.Write([]byte("tmp.txt"))
    if err != nil {
        fmt.Println(err)
        return err
    }
    stdin.Close()
    cmd.Stdout = os.Stdout     //终端标准输出tmp.txt
    cmd.Start()
    return nil
}

func exec_cmd6(cmd_str string) error {
    cmd := exec.Command("ls")
    stdout, err := cmd.StdoutPipe()
    cmd.Start()
    content, err := ioutil.ReadAll(stdout)
    if err != nil {
        fmt.Println(err)
        return err
    }
    fmt.Println(string(content))
    return nil
}

func main() {
    fmt.Println("calling exec_cmd1:")
    exec_cmd1("ls")
    fmt.Println("calling exec_cmd2:")
    exec_cmd2("ls")
    fmt.Println("calling exec_cmd3:")
    exec_cmd3("ls")
    fmt.Println("calling exec_cmd4:")
    exec_cmd4("ls")
    fmt.Println("calling exec_cmd5:")
    exec_cmd5("ls")
    fmt.Println("calling exec_cmd6:")
    exec_cmd6("ls")
}
