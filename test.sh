#!/bin/sh

current_tag=$(git describe --tags HEAD 2>/dev/null)
if [ -n "$current_tag" ]; then
    tags=$(git tag --sort=-version:refname)
    index=0
    found=0
    for tag in $tags; do
        if [ "$tag" = "$current_tag" ]; then
            found=1
            break
        fi
        index=$((index + 1))
    done

    if [ $found -eq 1 ]; then
        if [ $index -gt 0 ]; then
            tag_index=$((index - 1))
	    echo $tag_index
        else
            echo "No suitable tags found. Maybe run with '--topo-order'?"
            exit 1
        fi
    fi
else
    echo "No suitable tags found. Maybe run with '--topo-order'?"
    exit 1
fi

