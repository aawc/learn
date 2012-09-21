#!/usr/bin/env perl

use strict;
use warnings;

my %options = ();
my $lines = 0;

foreach my $line (<>) {
    if ($line =~ m/^(\d+)$/) {
        $lines = $1;
    }
    
    if (0 == $lines) { last; }
    
    if ($line =~ m/^([^ ]+) (-?\d+)$/) {
        $options{$1} = $2;
        $lines --;
    }
}

my @options = (sort keys %options);

my @comb_options = combinations(0..$#options);

foreach my $pick (@comb_options) {
    if ( -1 == $#{$pick} ) { next; }
    
    my $total = 0;
    map $total += $options{$options[$_]}, @{$pick};
    
    if (0 == $total) {
        my @solution = ();
        foreach my $index (@{$pick})      { push @solution, $options[$index]; }
        foreach my $item (sort @solution) { print "$item\n"; }
        
        exit;
    }
}

print "no solution\n";

# permute and combinations from http://www.perlmonks.org/?node_id=24270
sub combinations {
    return [] unless @_;
    my $first = shift;
    my @rest = combinations(@_);
    return @rest, map { [$first, @$_] } @rest;
} 
