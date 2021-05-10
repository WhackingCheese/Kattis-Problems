import json

problems = json.loads(open("problems.json", "r", encoding="utf-8").read())
README = open("README.md", "w", encoding="utf-8")

text = "Problem | Solution | Languange\n--- | --- | --- \n"
for problem in problems["problems"]:
    if "url" in problem:
        text += f"[{problem['name']}]({problem['url']}{problem['id']})"
    else:
        text += f"[{problem['name']}]({problems['kattisURL']}{problem['id']})"
    text += " | "
    text += f"[{problem['id']}]({problem['id']})"
    text += " | "
    text += problem['lang']
    text += "\n"

README.write(text)
