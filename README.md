# CTF #044 — The Twisted Pointer

PWN / HARD / 450

Analyze `twisted_pointer`. The note manager has a use-after-free vulnerability. A freed `Note` chunk is reused by a new allocation of the same size; the stale pointer still references it. The challenge exposes a function pointer (`action`) in the object. Recover `win` and overwrite the dangling object's function pointer, then invoke `run`.

Flag: `CYBERWOLF{use_after_free_reclaimed}`
