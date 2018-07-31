const { app, BrowserWindow } = require('electron')

let win

function createWindow() {
  win = new BrowserWindow({ width: 800, height: 600, backgroundColor: '#000' })
  win.loadURL(`file://${__dirname}/index.html`)
  win.on('closed', () => { win = null })
}

app.on('ready', createWindow)
app.on('window-all-closed', () => { app.quit() })
