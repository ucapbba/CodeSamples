import os
import urllib.request
from tqdm import tqdm

# Define a progress bar function
class DownloadProgressBar(tqdm):
    def update_to(self, b=1, bsize=1, tsize=None):
        if tsize is not None:
            self.total = tsize
        self.update(b * bsize - self.n)

# Check if the data file already exists
data_path = "catalog.fits"
if not os.path.exists(data_path):
    url = "https://zenodo.org/records/13622599/files/catalog.fits?download=1&preview=1"
    with DownloadProgressBar(unit='B', unit_scale=True, miniters=1, desc=data_path) as t:
        urllib.request.urlretrieve(url, data_path, reporthook=t.update_to)
else:
    print("Data is already cached.")