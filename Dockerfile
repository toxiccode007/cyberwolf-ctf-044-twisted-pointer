FROM debian:bookworm-slim
RUN apt-get update && apt-get install -y --no-install-recommends gcc libc6-dev && rm -rf /var/lib/apt/lists/*
WORKDIR /app
COPY . .
RUN gcc -O0 -fno-stack-protector -no-pie -o challenge_files/twisted_pointer challenge_files/twisted_pointer.c && rm challenge_files/twisted_pointer.c
CMD ["sh","-c","python3 app.py"]
