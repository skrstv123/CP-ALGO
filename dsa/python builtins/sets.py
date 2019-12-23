"""
set operations
# & intersection
# | union 
# ^ symm difference
# .add to add new elements
# .difference to find difference b/w two sets
# .pop() removes an item

"""

'''
a set is mutable and unhashable
a frozenset is immutable and hashable
A set of sets is not possible but a set of frozensets is possible
'''
a = set([5,6,7])
a.add(frozenset([4,5,6]))
print(a)