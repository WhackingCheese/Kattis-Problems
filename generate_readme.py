import json

problems = json.loads(open("problems.json", "r", encoding="utf-8").read())
README = open("README.md", "w", encoding="utf-8")

text = "# My solutions to kattis competitive programming problems\n\nProblem | Solution | Languange\n:--- | :--- | :--- \n"
for problem in problems["problems"]:
    if "url" in problem:
        text += f"[{problem['name']}]({problem['url']}{problem['id']})"
    else:
        text += f"[{problem['name']}]({problems['kattisURL']}{problem['id']})"
    text += " | "
    text += f"[{problem['id']}](problems/{problem['id']}.{problem['lang']})"
    text += " | "
    if problem['lang'] == 'py':
        text += "Python 3"
    elif problem['lang'] == 'c':
        text += "C"
    else:
        text += problem['lang'].capitalize()
    text += "\n"

README.write(text)
