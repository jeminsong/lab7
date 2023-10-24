#!/usr/bin/env python3
#
# Copyright 2021-2023 Michael Shafae
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice,
#    this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
""" Check student's submission; requires the main file and the
    template file from the original repository. """
# pexpect documentation
#  https://pexpect.readthedocs.io/en/stable/index.html

# ex.
# .action/solution_check_p1.py  part-1 asgt

import io
import math
import sys
import os
import re
import pexpect
from assessment import csv_solution_check_make
from logger import setup_logger

import lab_config as cfg


def regex_it(s):
    combine_white_space_regex = re.compile(r"\s+")
    s = combine_white_space_regex.sub(" ", s).strip()
    s = s.replace(' ', '\\s+').replace('\n', '\\s+')
    return f'\\s*{s}\\s*'

def run_p1(binary):
    """Run part-1 Datediff"""
    logger = setup_logger()
    status = []
    error_values = (
        ('', 'Please provide a starting date and an ending date. Exiting.',),
        (1, 'Please provide a starting date and an ending date. Exiting.',),
        (
            1,
            2,
            'Please provide a starting date and an ending date. Exiting.',
        ),
        (
            1,
            2,
            3,
            'Please provide a starting date and an ending date. Exiting.',
        ),
        (
            1,
            2,
            3,
            4,
            'Please provide a starting date and an ending date. Exiting.',
        ),
        (
            1,
            2,
            3,
            4,
            5,
            'Please provide a starting date and an ending date. Exiting.',
        ),
    )
    values = (
        (1, 1, 2022, 1, 1, 2023, 365),
        (1, 1, 1984, 1, 1, 1985, 366),
        (12, 25, 1275, 12, 25, 2522, 455457),
        (9, 21, 2022, 10, 31, 1980, -15300),
        (10, 1, 79, 9, 23, 2022, 709658),
    )

    for index, val in enumerate(error_values):
        test_number = index + 1
        logger.info('Test %d - %s', test_number, val)
        rv = _run_p1_error(binary, val)
        if not rv:
            logger.error(
                "Did not receive expected response for test %d.", test_number
            )
        status.append(rv)

    for index, val in enumerate(values):
        logger.info('Test %d - %s', index + 1, val)
        # status = status and _run_p1(binary, val)
        rv = _run_p1(binary, val)
        if not rv:
            logger.error(
                "Did not receive expected response for test %d.", index + 1
            )
        status.append(rv)
    return status


def _run_p1_error(binary, values):
    logger = setup_logger()
    status = False
    
    values = list(map(str, values))
    expected = values[-1]

    part_path = os.path.dirname(os.path.abspath(binary))
    proc = pexpect.spawn(command=binary, args=values[:len(values) - 1], timeout=1, cwd=part_path)
    with io.BytesIO() as log_stream:
        proc.logfile = log_stream
        regex_expected = regex_it(expected)
        try:
            proc.expect(
                fr'(?i){regex_expected}'
            )
        except (pexpect.exceptions.TIMEOUT, pexpect.exceptions.EOF) as exception:
            logger.error('Could not find expected output.')
            logger.error(f'Expected "{expected_output}"')
            logger.error('Your output: "%s"', log_stream.getvalue().decode('utf-8'))
            logger.info("%s", str(exception))
            logger.debug(str(proc))
            return status
        
        proc.expect(pexpect.EOF)
        proc.close()                

        if proc.exitstatus == 0:
            logger.error("Expected: non-zero exit code.")
            logger.error(f"Exit code was {proc.exitstatus}.")
            logger.error("Program returned zero, but non-zero is required")
            logger.error('Your output: "%s"', log_stream.getvalue().decode("utf-8"))
            return status
        
    status = True
    return status


def _run_p1(binary, values):
    """The actual test with the expected input and output"""
    logger = setup_logger()
    status = False
    
    values = list(map(str, values))
    expected_output = 'The number of days between {}/{}/{} and {}/{}/{} is {} days.'.format(
                *values
            )

    part_path = os.path.dirname(os.path.abspath(binary))
    proc = pexpect.spawn(command=binary, args=values[:6], timeout=1, cwd=part_path)

    # CLI program, no prompts
    # prompts = [ ]

    with io.BytesIO() as log_stream:
        proc.logfile = log_stream
        regex_expected = regex_it(expected_output)
        try:
            proc.expect(
                fr'(?i){regex_expected}'
            )
        except (pexpect.exceptions.TIMEOUT, pexpect.exceptions.EOF) as exception:
            logger.error('Could not find expected output.')
            logger.error(f'Expected "{expected_output}"')
            logger.error('Your output: "%s"', log_stream.getvalue().decode('utf-8'))
            logger.info("%s", str(exception))
            logger.debug(str(proc))
            return status
        
        proc.expect(pexpect.EOF)
        proc.close()                

        if proc.exitstatus != 0:
            logger.error("Expected: zero exit code.")
            logger.error(f"Exit code was {proc.exitstatus}.")
            logger.error("Program returned non-zero, but zero is required")
            logger.error('Your output: "%s"', log_stream.getvalue().decode("utf-8"))
            return status
        
    status = True
    return status

def run_p2(binary):
    """Run part-2 Parking"""
    logger = setup_logger()
    status = []
    error_values = (
        ('error: you must supply four arguments',),
        ('a', 'b', 'c', 'd', 'e', 'error: you must supply four arguments',),
        ('main', 'wed', '11', '0', 'error: invalid street',),
        ('ash', 'yesterday', '11', '0', 'error: invalid day',),
        ('ash', 'mon', '-1', '0', 'error: invalid hour',),
        ('ash', 'mon', '25', '0', 'error: invalid hour',),
        ('ash', 'mon', '11', '-1', 'error: invalid minute',),
        ('ash', 'mon', '11', '60', 'error: invalid minute',),
    )
    values = (
        ('ash', 'mon', '11', '0', 'allowed',),
        ('ash', 'wed', '11', '0', 'not allowed',),
        ('beech', 'thu', '8', '30', 'allowed',),
        ('beech', 'fri', '8', '30', 'not allowed',),
        ('cedar', 'mon', '13', '20', 'allowed',),
        ('cedar', 'tue', '1', '40', 'not allowed',),
        ('cedar', 'tue', '9', '0', 'not allowed',),
        ('date', 'sat', '14', '0', 'allowed',),
        ('date', 'sun', '15', '0', 'allowed',),
        ('date', 'mon', '14', '30', 'not allowed',),
        ('elm', 'fri', '18', '0', 'allowed',),
        ('elm', 'fri', '16', '0', 'not allowed',),
    )

    for index, val in enumerate(error_values):
        test_number = index + 1
        logger.info('Test %d - %s', test_number, val)
        rv = _run_p2_error(binary, val)
        if not rv:
            logger.error(
                "Did not receive expected response for test %d.", test_number
            )
        status.append(rv)

    for index, val in enumerate(values):
        logger.info('Test %d - %s', index + 1, val)
        rv = _run_p2(binary, val)
        if not rv:
            logger.error(
                "Did not receive expected response for test %d.", index + 1
            )
        status.append(rv)

    return status

def _run_p2_error(binary, values):
    logger = setup_logger()
    status = False

    arguments = list(values[:-1])
    expected = values[-1]

    part_path = os.path.dirname(os.path.abspath(binary))
    proc = pexpect.spawn(command=binary, args=arguments, timeout=1, cwd=part_path)
    with io.BytesIO() as log_stream:
        proc.logfile = log_stream
        regex_expected = regex_it(expected)
        try:
            proc.expect(
                fr'(?i){regex_expected}'
            )
        except (pexpect.exceptions.TIMEOUT, pexpect.exceptions.EOF) as exception:
            logger.error('Could not find expected output.')
            logger.error(f'Expected "{expected}"')
            logger.error('Your output: "%s"', log_stream.getvalue().decode('utf-8'))
            logger.info("%s", str(exception))
            logger.debug(str(proc))
            return status
        
        proc.expect(pexpect.EOF)
        proc.close()

        if proc.exitstatus == 0:
            logger.error("Expected: non-zero exit code.")
            logger.error(f"Exit code was {proc.exitstatus}.")
            logger.error("Program returned zero, but non-zero is required")
            logger.error('Your output: "%s"', log_stream.getvalue().decode("utf-8"))
            return status
        
    status = True
    return status

def _run_p2(binary, values):
    """The actual test with the expected input and output"""
    logger = setup_logger()
    status = False
    
    arguments = list(values[:-1])
    expected = values[-1]

    part_path = os.path.dirname(os.path.abspath(binary))
    proc = pexpect.spawn(command=binary, args=arguments, timeout=1, cwd=part_path)

    with io.BytesIO() as log_stream:
        proc.logfile = log_stream
        regex_expected = regex_it(expected)
        try:
            proc.expect(
                fr'(?i){regex_expected}'
            )
        except (pexpect.exceptions.TIMEOUT, pexpect.exceptions.EOF) as exception:
            logger.error('Could not find expected output.')
            logger.error(f'Expected "{expected}"')
            logger.error('Your output: "%s"', log_stream.getvalue().decode('utf-8'))
            logger.info("%s", str(exception))
            logger.debug(str(proc))
            return status
        
        proc.expect(pexpect.EOF)
        proc.close()                

        if proc.exitstatus != 0:
            logger.error("Expected: zero exit code.")
            logger.error(f"Exit code was {proc.exitstatus}.")
            logger.error("Program returned non-zero, but zero is required")
            logger.error('Your output: "%s"', log_stream.getvalue().decode("utf-8"))
            return status
        
    status = True
    return status

if __name__ == '__main__':
    cwd = os.getcwd()
    repo_name = os.path.basename(cwd)
    td = sys.argv[1]
    # print(td)
    if sys.argv[1] == 'part-1':
        part_config = cfg.lab['parts'][0]
    elif sys.argv[1] == 'part-2':
        part_config = cfg.lab['parts'][1]
    else:
        print(f'Error: {sys.argv[0]} no match.')
        sys.exit(1)

    _program_name = part_config['target']
    _files = part_config['src'].split() + part_config['header'].split()
    _do_format_check = part_config['do_format_check']
    _do_lint_check = part_config['do_lint_check']
    _do_unit_tests = part_config['do_unit_tests']
    _tidy_options = part_config['tidy_opts']
    _skip_compile_cmd = part_config['skip_compile_cmd']
    # There needs to be some magic here to figure out which due date to use.
    _lab_due_date = cfg.lab['mon_duedate'].isoformat()
    _run_func = locals()[part_config['test_main']]

    # Execute the solution check
    csv_solution_check_make(
        csv_key=repo_name,
        target_directory=td,
        program_name=_program_name,
        run=_run_func,
        files=_files,
        do_format_check=_do_format_check,
        do_lint_check=_do_lint_check,
        do_unit_tests=_do_unit_tests,
        tidy_options=_tidy_options,
        skip_compile_cmd=_skip_compile_cmd,
        lab_due_date=_lab_due_date,
    )
