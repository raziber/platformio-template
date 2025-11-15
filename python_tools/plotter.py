import serial
import pyqtgraph as pg
from pyqtgraph.Qt import QtCore, QtWidgets

ser = serial.Serial('COM10', 9600, timeout=1)

app = QtWidgets.QApplication([])
win = pg.GraphicsLayoutWidget(show=True, title="Live Plot")
plot = win.addPlot()
curve = plot.plot()

data = []

def update():
    line = ser.readline().decode(errors="ignore").strip()
    if line.isdigit():
        data.append(int(line))
        curve.setData(data[-300:])

timer = QtCore.QTimer()
timer.timeout.connect(update)
timer.start(1)

QtWidgets.QApplication.instance().exec()
