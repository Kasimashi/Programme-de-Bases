#!/usr/bin/python3

with open('somefile.txt', 'a') as the_file:

    for i in range(100):
        the_file.write("Message {}\n".format(i))
