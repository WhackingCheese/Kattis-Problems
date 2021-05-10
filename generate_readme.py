import json

REPO = "https://github.com/WhackingCheese/Kattis-Problems/blob/main/problems/"
problems = json.loads(open("problems.json", "r", encoding="utf-8").read())
README = open("README.md", "w", encoding="utf-8")

text = "Problem | Solution | Languange\n--- | --- | --- \n"
for problem in problems["problems"]:
    if "url" in problem:
        text += f"[{problem['name']}]({problem['url']}{problem['id']})"
    else:
        text += f"[{problem['name']}]({problems['kattisURL']}{problem['id']})"
    text += " | "
    text += f"[{problem['id']}]({REPO}/{problem['id']}.{problem['lang']})"
    text += " | "
    if problem['lang'] == 'py':
        text += "Python 3"
    else:
        text += "C"
    text += "\n"

README.write(text)
