self.onmessage = async (e) => {
  const bitmap = e.data.bitmap;
  // Simulate processing - echo back the same bitmap
  self.postMessage(bitmap, [bitmap]);
};
