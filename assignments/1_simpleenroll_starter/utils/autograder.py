'''
Hey friend! Glad you're curious about this, but please don't touch this file :>)
'''

from csv_utils import *
import os
import sys
import io
sys.stdout = io.TextIOWrapper(sys.stdout.buffer,encoding='utf8')

def main():
  # fstream writing tests!
  binary_to_csv("D:\\workspace\\CS106L\\assignments\\1_simpleenroll_starter\\utils\\courses_not_offered.bin", "D:\\workspace\\CS106L\\assignments\\1_simpleenroll_starter\\utils\\courses_not_offered.csv")
  binary_to_csv("D:\\workspace\\CS106L\\assignments\\1_simpleenroll_starter\\utils\\courses_offered.bin", "D:\\workspace\\CS106L\\assignments\\1_simpleenroll_starter\\utils\\courses_offered.csv")
  assert files_are_equal("D:\\workspace\\CS106L\\assignments\\1_simpleenroll_starter\\utils\\courses_offered.csv", "D:\\workspace\\CS106L\\assignments\\1_simpleenroll_starter\\student_output\\courses_offered.csv"), "write_courses_offered test failed 😞"
  assert files_are_equal("D:\\workspace\\CS106L\\assignments\\1_simpleenroll_starter\\utils\\courses_not_offered.csv", "D:\\workspace\\CS106L\\assignments\\1_simpleenroll_starter\\student_output\\courses_not_offered.csv"), "write_courses_not_offered test failed 😞"
  os.remove("D:\\workspace\\CS106L\\assignments\\1_simpleenroll_starter\\utils\\courses_not_offered.csv")
  os.remove("D:\\workspace\\CS106L\\assignments\\1_simpleenroll_starter\\utils\\courses_offered.csv")
  print("Congratulations, your code passes all the autograder tests! ✅")

main()