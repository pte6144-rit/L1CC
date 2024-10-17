#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys
import numpy as np
import matplotlib.pyplot as plt

def main(filename, n=64):

    with open(filename, 'r') as fp:
        lats = fp.read().strip()
        lats = list(map(lambda a: float(a.strip()) if len(a) <= 4 else 100, lats.split(' ')))
        print(sum(lats)/len(lats))
    lats = np.reshape(lats, (-1,n))
    lats = lats.transpose()
    print(lats)
    plt.figure()
    plt.imshow(lats, cmap='gray', interpolation='nearest')
    #plt.colorbar()
    plt.show()

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print('usage: python %s <raw.bin>' % sys.argv[0])
        sys.exit(1)
    else:
        main(sys.argv[1])
