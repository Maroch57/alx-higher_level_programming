#!/usr/bin/python3
"""using the GitHub API to list commits URL = "https://api.github.com"""

import requests
import sys

if __name__ == "__main__":

    repository_name = sys.argv[1]
    owner_name = sys.argv[2]

    # GitHub API URL
    url = 'https://api.github.com/repos/{}/{}/commits'.format(
        sys.argv[2], sys.argv[1])

    params = {'per_page': 10}

    # send a GET request to the GitHub API
    response = requests.get(url, params=params)

    # parse the JSON response
    commits = response.json()
    for commit in commits:
        sha = commit['sha']
        author_name = commit['commit']['author']['name']
        print(f"{sha}: {author_name}")
