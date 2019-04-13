from __future__ import print_function

import thinkplot
import matplotlib.pyplot as pyplot

d = {}
for line in open('data'):
    t = line.split()
    size, hash, time = int(t[1]), int(t[3]), float(t[4])
    d.setdefault(hash, []).append((size, time))


thinkplot.PrePlot(num=6)
for hash in sorted(d.keys()):
    if hash >= 7: continue

    xs, ys = zip(*d[hash])
    thinkplot.plot(xs, ys, label=str(hash))
    print(hash, len(d[hash]))

pyplot.xscale('log', basex=10)
thinkplot.show(xlabel='Array Size', ylabel='Time (s)')
