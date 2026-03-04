# BMES-PulseOx
Our team's files for the BMES Build Team Pulse Oximeter

## filterFinder.py
Use in the command line with
```bash
$ python filterFinder.py
```
and input the pole frequency and sampling frequency in Hertz

Example usage:
```bash
python filterFinder.py

Pole frequency (Hz): 5
Sampling frequency (Hz): 1000

yFiltered =
0.9690699219933061 * lastFiltered +
0.015465039003346948 * yInput +
0.015465039003347059 * lastInput
```
