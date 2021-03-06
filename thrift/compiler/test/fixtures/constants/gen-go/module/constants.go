// Autogenerated by Thrift Compiler (facebook)
// DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
// @generated

package module

import (
	"bytes"
	"fmt"
	"git.apache.org/thrift.git/lib/go/thrift"
)

// (needed to ensure safety because of naive import list construction.)
var _ = thrift.ZERO
var _ = fmt.Printf
var _ = bytes.Equal

const MyInt = 1337
const Name = "Mark Zuckerberg"
var States []map[string]int32
const X = 1
const Y = 1000000
const Z = 1e+09
var Instagram *Internship
var KRanges []*Range
var InternList []*Internship
const Apostrophe = "'"
const TripleApostrophe = "'''"
const QuotationMark = "\""
const Backslash = "\\\\"
const EscapedA = "\\x61"
var Char2ascii map[string]int32
var EscapedStrings []string
const FalseC = false
const TrueC = true
const ZeroByte = 0
const Zero16 = 0
const Zero32 = 0
const Zero64 = 0
const ZeroDotZero = 0
const EmptyString = ""
var EmptyIntList []int32
var EmptyStringList []string
var EmptyIntSet map[int32]bool
var EmptyStringSet map[string]bool
var EmptyIntIntMap map[int32]int32
var EmptyIntStringMap map[int32]string
var EmptyStringIntMap map[string]int32
var EmptyStringStringMap map[string]string

func init() {
States = []map[string]int32{
  map[string]int32{
    "San Diego": 3211000,
    "Sacramento": 479600,
    "SF": 837400,
  },   map[string]int32{
    "New York": 8406000,
    "Albany": 98400,
  }, }

Instagram = &Internship{
  Weeks: 12,
  Title: "Software Engineer",
  Employer:   3,}

KRanges = []*Range{
  &Range{
    Min: 1,
    Max: 2,},   &Range{
    Min: 5,
    Max: 6,}, }

InternList = []*Internship{
  &Internship{
    Weeks: 12,
    Title: "Software Engineer",
    Employer:     3,},   &Internship{
    Weeks: 10,
    Title: "Sales Intern",
    Employer:     0,}, }

Char2ascii = map[string]int32{
  "'": 39,
  "\"": 34,
  "\\\\": 92,
  "\\x61": 97,
}

EscapedStrings = []string{
  "\\x61",   "\\xab",   "\\x6a",   "\\xa6",   "\\x61yyy",   "\\xabyyy",   "\\x6ayyy",   "\\xa6yyy",   "zzz\\x61",   "zzz\\xab",   "zzz\\x6a",   "zzz\\xa6",   "zzz\\x61yyy",   "zzz\\xabyyy",   "zzz\\x6ayyy",   "zzz\\xa6yyy", }

EmptyIntList = []int32{
}

EmptyStringList = []string{
}

EmptyIntSet = map[int32]bool{
}

EmptyStringSet = map[string]bool{
}

EmptyIntIntMap = map[int32]int32{
}

EmptyIntStringMap = map[int32]string{
}

EmptyStringIntMap = map[string]int32{
}

EmptyStringStringMap = map[string]string{
}

}

