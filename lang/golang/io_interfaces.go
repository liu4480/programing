package main

/**
* @file io_interfaces.go
* @brief
* @author bliu@suse.com
* @version 0.1.00
* @date 2018-05-08
 */
import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	//unbuffered
	fmt.Fprintf(os.Stderr, "%s\n", "Hello world! - unbuffered")
	//buffered: os.Stdout implements io.Writer
	buf := bufio.NewWriter(os.Stdout)
	fmt.Fprintf(buf, "%s\n", "Hello world! - buffered")
	buf.Flush()
}
