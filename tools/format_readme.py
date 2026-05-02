import re
from pathlib import Path

P = Path(r"c:\Users\hp\Desktop\dsa practical\README.md")
text = P.read_text(encoding='utf-8')

# Bold the small top heading and all Practical headings
text = re.sub(r'^(####\s+)(.+)$', r"\1**\2**", text, flags=re.M)
text = re.sub(r'^(###\s+)(Practical\s+\d+\.\s+.+)$', r"\1**\2**", text, flags=re.M)

# Replace Code: sections with fenced C++ blocks and indent code lines (preserve existing fenced blocks)
pattern = re.compile(r'(Code:\s*\n\s*\n)(.*?)(\n\s*\nGraph:)', re.S)
def repl(m):
    code = m.group(2)
    lines = code.splitlines()
    # Trim surrounding blank lines
    while lines and lines[0].strip() == '':
        lines.pop(0)
    while lines and lines[-1].strip() == '':
        lines.pop()
    indented = '\n'.join('    ' + ln.rstrip() for ln in lines)
    return 'Code:\n\n```cpp\n' + indented + '\n```\n\nGraph:'

text = pattern.sub(repl, text)

P.write_text(text, encoding='utf-8')
print('README formatted')

# Now also bold common section labels
labels = {
    'Problem Statement:': '**Problem Statement:**',
    'Algorithm of Solution:': '**Algorithm of Solution:**',
    'Code:': '**Code:**',
    'Graph:': '**Graph:**',
    'Time Complexity:': '**Time Complexity:**',
    'Space Complexity:': '**Space Complexity:**'
}

s = P.read_text(encoding='utf-8')
for k,v in labels.items():
    s = s.replace(k, v)
P.write_text(s, encoding='utf-8')
print('Labels bolded')

# Cleanup nested/indented fences and excessive bolding
from pathlib import Path
lines = P.read_text(encoding='utf-8').splitlines()
out = []
in_code = False
for ln in lines:
    # normalize excessive asterisks
    ln = ln.replace('****', '**')
    # detect outer fence (no leading spaces)
    if re.match(r'^```', ln):
        # toggle outer fence
        in_code = not in_code
        out.append('```cpp' if ln.strip().startswith('```cpp') else '```')
        continue
    # skip indented fence markers inside code blocks
    if in_code and re.match(r'^\s+```', ln):
        continue
    # if inside code and line has 4 or more leading spaces, strip 4 spaces
    if in_code and ln.startswith('    '):
        out.append(ln[4:])
    else:
        out.append(ln)

P.write_text('\n'.join(out) + '\n', encoding='utf-8')
print('Cleaned nested fences and normalized bolding')

# Final pass: remove up to 4 leading spaces inside fenced code blocks
s = P.read_text(encoding='utf-8')
out_lines = []
in_code = False
for line in s.splitlines():
    if line.strip().startswith('```'):
        in_code = not in_code
        out_lines.append(line)
        continue
    if in_code:
        if line.startswith('    '):
            out_lines.append(line[4:])
        else:
            out_lines.append(line)
    else:
        out_lines.append(line)
P.write_text('\n'.join(out_lines) + '\n', encoding='utf-8')
print('Stripped leading spaces inside fenced code')
