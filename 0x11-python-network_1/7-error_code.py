#!/usr/bin/python3
"""using requests module to fetch"""

import sys
import requests


if __name__ == "__main__":
    # get  URL from the command line
    url = sys.argv[1]

    # Send GET request to the specified URL
    response = requests.get(url)

    # Check if HTTP status code error
    if response.status_code >= 400:
        print("Error code: {}".format(response.status_code))
    else:
        print(response.text)
