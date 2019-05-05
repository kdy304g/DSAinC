from __future__ import print_function

import thinkplot
import matplotlib.pyplot as pyplot

d = {}
sizes = [[] for i in range(6)]
speeds = [[] for i in range(6)]
for line in open('speedData'):
    t = line.split()
    size, hash, time = int(t[1]), int(t[3]), float(t[4])
    # d.setdefault(hash, []).append((size, time))
    sizes[hash-1].append(size)
    speeds[hash-1].append(time)

fig = pyplot.figure()
ax = fig.add_subplot(111)
for num in range(6):
    pyplot.scatter(sizes[num], speeds[num], s = .01)
ax.set_title("Hash Speeds")
ax.set_xlabel("Size of List")
ax.set_ylabel("Speed")
pyplot.savefig('SpeedHash.png')


# thinkplot.PrePlot(num=6)
# for hash in sorted(d.keys()):
#     if hash >= 7: continue
#
#     xs, ys = zip(*d[hash])
#     thinkplot.plot(xs, ys, label=str(hash))
#     print(hash, len(d[hash]))
# pyplot.savefig('HashSpeed.png')
# thinkplot.show(title = 'Hash Speed',xlabel='Array Size', ylabel='Time (s)')
# #
# lens =[[] for i in range(6)]
# vals =[[] for i in range(6)]
# freqs =[{} for i in range(6)]
# for line in open('colLenData'):
#     t = line.split()
#     hash, len, val = int(t[1]), int(t[3]), int(t[5])
#     lens[hash-1].append(len)
#     vals[hash-1].append(val)# print(here)
#     if val in freqs[hash-1]:
#         freqs[hash-1][val] += 1
#     else:
#         freqs[hash-1][val] = 1
# # print(freqs[0])
#
# for num in range(6):
# # num = 3
#     fig = pyplot.figure(num)
#     ax = fig.add_subplot(111)
#     pyplot.figure(num)
#     pyplot.scatter(lens[num], vals[num], s = .01)
#     ax.set_title("Bad Hash Values by Length: Hash" + str(num+1))
#     ax.set_xlabel("Length of Word")
#     ax.set_ylabel("Hash Value")
#     pyplot.savefig('Hash ' + str(num+1) + ' Length.png')
#
#
#
# for num in range(6):
#
#     # print(num)
#     fig = pyplot.figure(num+6)
#     ax = fig.add_subplot(111)
#     pyplot.scatter(freqs[num].keys(), freqs[num].values(), s = 1)
#
#     ax.set_title("Distribution: Hash" + str(num+1))
#     ax.set_xlabel("Hash Value")
#     ax.set_ylabel("Frequency")
#     pyplot.savefig('Hash ' + str(num+1) + ' Distribution.png')
#
# # pyplot.show()
