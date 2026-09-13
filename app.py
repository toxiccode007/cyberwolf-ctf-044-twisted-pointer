import os, socket, subprocess
from flask import Flask, render_template_string, send_file
app=Flask(__name__)
HTML="""<!doctype html><html><head><title>CTF #044</title><style>
body{background:#070b12;color:#d9f7ff;font-family:Arial;padding:40px}h1{color:#45d9ff}pre{background:#101722;padding:20px;border-radius:10px;overflow:auto}.tag{color:#ff5c70}</style></head>
<body><h1>🐺 The Twisted Pointer</h1><p>Analyze the supplied Linux ELF and recover the flag.</p><p class="tag">Challenge file:</p><a href="/download">twisted_pointer</a><h2>Goal</h2><p>Investigate the note manager and exploit the memory-lifetime bug.</p></body></html>"""
@app.get("/")
def index(): return render_template_string(HTML)
@app.get("/download")
def download(): return send_file("/app/challenge_files/twisted_pointer", as_attachment=True, download_name="twisted_pointer")
@app.get("/health")
def health(): return {"status":"ok"}
if __name__=="__main__": app.run(host="0.0.0.0",port=int(os.environ.get("PORT",5000)))
