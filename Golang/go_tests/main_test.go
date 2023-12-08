package main

import "testing"

// Name, a,b,want,error
var tests = []struct {
	name  string
	a     float32
	b     float32
	want  float32
	isErr bool
}{
	{"Test1", 10, 2.0, 5.0, false},
	{"Test2", 10, 2.0, 4.0, true},
	{"Test3", 20, 2.0, 5.0, false},
	{"Test4", 10, 2.0, 5.0, false},
}

func TestDivide(t *testing.T) {
	for _, tt := range tests {
		want, err := divide(tt.a, tt.b)
		if (err != nil) != tt.isErr {
			t.Errorf("%s : got error %v, want error %v", tt.name, err, tt.isErr)
		}
		if want != tt.want {
			t.Errorf("%s: got %v, want %v", tt.name, want, tt.want)
		}

	}
}
