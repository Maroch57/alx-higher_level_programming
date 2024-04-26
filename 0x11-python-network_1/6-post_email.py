#!/usr/bin/python3
"""using request module to fetch"""

import sys
import requests


if __name__ == "__main__":
    # get url from the command line
    url = sys.argv[1]
    email = sys.argv[2]

    # create dictionary with the email parameter
    data = {'email': email}

    # send POST request to the URL
    response = requests.post(url, data=data)
    print(response.text)
