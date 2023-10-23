#!/usr/bin/python3
"""Log parsing"""
import sys


def print_stats(total_size, status_codes):
    """ Print statistics about the size of the log file"""
    print("File size: {}".format(total_size))
    sorted_status_codes = sorted(status_codes.items())
    for code, count in sorted_status_codes:
        print("{}: {}".format(code, count))


def main():
    """Run the command line interface with the given arguments"""
    total_size = 0
    status_codes = {200: 0, 301: 0, 400: 0,
                    401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
    line_count = 0

    try:
        for line in sys.stdin:
            parts = line.split()
            if len(parts) >= 7:
                status_code = int(parts[-2])
                file_size = int(parts[-1])
                if status_code in status_codes:
                    status_codes[status_code] += 1
                total_size += file_size
                line_count += 1

            if line_count % 10 == 0:
                print_stats(total_size, status_codes)

    except KeyboardInterrupt:
        pass

    print_stats(total_size, status_codes)


if __name__ == "__main__":
    main()
