#!/usr/bin/python3

import os.path
import json
import random

DATA_FILE = 'data.json'


# class Problem:
#     def __init__(self, id, name, desc):
#         self.id = id
#         self.name = name
#         self.desc = desc
#     pass


def load():
    if not os.path.exists(DATA_FILE) or os.path.getsize(DATA_FILE) == 0:
        with open(DATA_FILE, 'w+') as f:
            f.write('{ "data": [] }')

    with open(DATA_FILE, 'r') as f:
        dt = json.load(f)
        if 'data' not in dt:
            dt['data'] = []
        return dt


def sink(dt):
    with open(DATA_FILE, 'w+') as f:
        json.dump(dt, f, indent=4)


def add():
    name = input('name: ')
    desc = input('desc: ')
    dt = load()
    dt['data'].append({'name': name, 'desc': desc})
    sink(dt)


def take():
    dt = load()['data']
    if len(dt) == 0:
        print('no candidate')
    else:
        ro = random.randint(0, len(dt) - 1)
        print(json.dumps(dt[ro], indent=4))


def remove():
    name = input('name: ')
    og = load()
    dt = og['data']
    tr = []
    for i in dt:
        if 'name' in i and i['name'] == name:
            tr.append(i)
    for i in tr:
        dt.remove(i)
    sink(og)

def show():
    dt = load()['data']
    print(json.dumps(dt, indent=4))


if __name__ == "__main__":
    while True:
        op = input('command [add|take|rm|show|quit] : ')
        if op == 'exit' or op == 'quit' or op == 'q':
            break
        elif op == 'add':
            add()
        elif op == 'take' or op == 'tk':
            take()
        elif op == 'remove' or op == 'rm':
            remove()
        elif op == 'show' or op == 'll':
            show()
        else:
            print('unkown operation', op)
