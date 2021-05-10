import requests, json, time, os

file = json.load(open("problems.json", "r", encoding="utf-8"))
count = 0
for problem in file['problems']:
    if not os.path.isfile(f"problems/{problem['id']}.{problem['lang']}"):
        print(f"file for problem \"{problem['name']}\" doesnt exist.")
        continue
    count += 1
    if 'url' in problem:
        data = requests.get(problem['url']+problem['id'])
        if data.status_code != 200:
            print(problem['id'])
            print(data.status_code)
        continue
    data = requests.get(file['kattisURL']+problem['id'])
    if data.status_code != 200:
        print(problem['id'])
        print(data.status_code)
print(f"Solved {count} problems thus far.")